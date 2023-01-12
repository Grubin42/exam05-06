#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include <iostream>
#include <string>
#include <vector>
class SpellBook;
#include "ASpell.hpp"

class SpellBook
{
private:
    std::vector<ASpell*> _book;

    SpellBook(SpellBook const &copy);
    SpellBook &operator=(SpellBook const &rhs);

public:
    SpellBook(){}
    virtual ~SpellBook()
    {
        std::vector<ASpell*>::iterator ite = this->_book.end();
        for(std::vector<ASpell*>::iterator it = this->_book.begin(); it != ite; ++it)
        {
            delete (*it);
        }
        this->_book.clear();
        
    }

    void learnSpell (ASpell *spell)
    {
        if (spell)
        {
            std::vector<ASpell*>::iterator ite = this->_book.end();
            for(std::vector<ASpell*>::iterator it = this->_book.begin(); it != ite; ++it)
            {
                if ((*it)->getName() == spell->getName())
                    return;
            }
            this->_book.push_back(spell->clone());
        }
    }
    void forgetSpell(std::string &name)
    {
        std::vector<ASpell*>::iterator ite = this->_book.end();
        for(std::vector<ASpell*>::iterator it = this->_book.begin(); it != ite; ++it)
        {
            if ((*it)->getName() == name)
            {
                delete (*it);
                it = this->_book.erase(it);
            }
        }
    }
    ASpell *createSpell (std::string const &name)
    {
        std::vector<ASpell*>::iterator ite = this->_book.end();
        for(std::vector<ASpell*>::iterator it = this->_book.begin(); it != ite; ++it)
        {
            if ((*it)->getName() == name)
            {
                return (*it);
            }
        }
        return NULL;
    }
};

#endif