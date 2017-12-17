//
// pch.h
// Header for standard system include files.
//

#pragma once

// Necessary headers
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

// Enum for managing employee type
enum EMP_TYPE
{
	FULLTIME = 0,
	CONTRACTOR,
	TEMPORARY
};

// Class used to store company employee info
class CompanyClass
{
private:
	// Employee data types
	EMP_TYPE employeeType;
	string employeeName;
	float employeeDuration;
	int vacationAccrued;
public:
	// Default empty constructor (for testing)
	CompanyClass() {};

	// Full constructor
	CompanyClass(string name, EMP_TYPE type, float duration)
	{
		setEmployeeName(name);
		setEmployeeType(type);
		setEmployeeDuration(duration);
		vacationAccrued = calcEmployeeVacation(employeeType, employeeDuration);
	}

	// Set private values
	void setEmployeeName(string name)
	{
		employeeName = name;
	}
	void setEmployeeType(EMP_TYPE type)
	{
		employeeType = type;
	}
	void setEmployeeDuration(float duration)
	{
		employeeDuration = duration;
	}

	// Get private values
	string getEmployeeName()
	{
		return employeeName;
	}
	string getEmployeeType()
	{
		switch (employeeType)
		{
		case FULLTIME:
			return "[FT]";
		case CONTRACTOR:
			return "[C]";
		case TEMPORARY:
			return "[T]";
		default:
			return "[ERROR]";
		}
	}

	// Return employee work duration
	float getEmployeeDuration()
	{
		return employeeDuration;
	}

	// Return employee vacation time
	int getEmployeeVacation()
	{
		return vacationAccrued;
	}

	// Calculate employee vacation
	int calcEmployeeVacation(EMP_TYPE type, float duration)
	{
		int daysPerYear = 5;

		if (type == FULLTIME)
			return (int)duration * daysPerYear;
		else
			return 0;
	}

	// Print full employee output
	void printEmployeeInfo()
	{
		cout << "Name: " << getEmployeeName() << getEmployeeType() << ", Duration: " << getEmployeeDuration() << " years, Vacation Accrued: " << getEmployeeVacation() << " days." << endl;
	}
};
