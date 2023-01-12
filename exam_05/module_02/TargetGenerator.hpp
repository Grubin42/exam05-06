#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

#include <iostream>
#include <string>
#include <vector>
class TargetGenerator;
#include "ATarget.hpp"

class TargetGenerator
{
private:
    std::vector<ATarget*> _target;

    TargetGenerator(TargetGenerator const &copy);
    TargetGenerator &operator=(TargetGenerator const &rhs);

public:
    TargetGenerator(){}
    virtual ~TargetGenerator()
    {
        std::vector<ATarget*>::iterator ite = this->_target.end();
        for(std::vector<ATarget*>::iterator it = this->_target.begin(); it != ite; ++it)
        {
            delete (*it);
        }
        this->_target.clear();
        
    }

    void learnTargetType (ATarget *type)
    {
        if (type)
        {
            std::vector<ATarget*>::iterator ite = this->_target.end();
            for(std::vector<ATarget*>::iterator it = this->_target.begin(); it != ite; ++it)
            {
                if ((*it)->getType() == type->getType())
                    return;
            }
            this->_target.push_back(type->clone());
        }
    }
    void forgetTargetType(std::string const &type)
    {
        std::vector<ATarget*>::iterator ite = this->_target.end();
        for(std::vector<ATarget*>::iterator it = this->_target.begin(); it != ite; ++it)
        {
            if ((*it)->getType() == type)
            {
                delete (*it);
                it = this->_target.erase(it);
            }
        }
    }
    ATarget *createTarget (std::string const &type)
    {
        std::vector<ATarget*>::iterator ite = this->_target.end();
        for(std::vector<ATarget*>::iterator it = this->_target.begin(); it != ite; ++it)
        {
            if ((*it)->getType() == type)
            {
                return (*it);
            }
        }
        return NULL;
    }
};

#endif