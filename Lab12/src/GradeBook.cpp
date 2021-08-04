#include "GradeBook.h"
#include "Grade.h"

int GradeBook::_numOfGrades = 0;

GradeBook::GradeBook(const char *gradeBookName): 
_grades(new Grade *[1]), _name(gradeBookName)
{
    _grades[0] = nullptr;
}

Grade &GradeBook::operator[](unsigned i) const
{
    return *_grades[i];
}

void GradeBook::Insert(Grade *grade)
{
    int initialLength = _numOfGrades;
    ++_numOfGrades;
    Grade **tempGrades = new Grade *[_numOfGrades];
    
    for(int i=0; i<initialLength; i++)
    {
        tempGrades[i] = _grades[i];
    }
    tempGrades[initialLength] = grade;
    
    delete [] _grades;
    _grades = tempGrades;
}

GradeBook::~GradeBook()
{
    for(int i=0; i<_numOfGrades; i++)
    {
        delete _grades[i];
    }

    delete [] _grades;
    _grades = nullptr;
}

std::ostream &operator<<(std::ostream &os, const GradeBook &grades)
{
    if(grades._grades[0] == nullptr)
    {
        std::cout << "[" << grades._name << "]: ";
        std::cout << "The GradeBook is empty";
    } else 
    {
        for(int i=0; i<grades._numOfGrades; i++)
        {
            std::cout << "[" << grades._name << "]: ";
            grades._grades[i]->Print();
            std::cout << std::endl;
        }
    }
    return os;
}

