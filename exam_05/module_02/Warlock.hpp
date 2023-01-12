#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <string>
#include <vector>
class Warlock;
#include "ATarget.hpp"
#include "SpellBook.hpp"
#include "ASpell.hpp"

class Warlock {

    private:
        std::string _name;
        std::string _title;

        SpellBook _book;

        Warlock();
        Warlock(Warlock const &copy);
        Warlock &operator=(Warlock const &rhs);

    public:
        Warlock(std::string name, std::string title)
        : _name(name), _title(title)
        {
            std::cout << this->_name << ": This looks like another boring day." << std::endl;
        }
        virtual ~Warlock()
        {
            std::cout << this->_name << ": My job here is done!" << std::endl;
        }
        const std::string &getName() const
        {
            return (this->_name);
        }
        const std::string &getTitle() const
        {
            return (this->_title);
        }
        void setTitle(std::string const &title)
        {
            this->_title = title;
        }
        void introduce() const
        {
            std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << std::endl;
        }
        void learnSpell (ASpell *spell)
        {
            this->_book.learnSpell(spell);
        }
        void forgetSpell(std::string name)
        {
            this->_book.forgetSpell(name);
        }
        void launchSpell(std::string name, ATarget &target)
        {
            ATarget const *test = 0;
            if (test == &target)
                return;
            ASpell *tmp = _book.createSpell(name);
            if (tmp)
            tmp->launch(target);
        }
};

#endif