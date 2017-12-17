# Company class storing our employee information
class company:
	employeeName = None;
	employeeType = None;
	employeeLength = None;
	employeeVacation = None;

# Fill the class with the information of an employee
def create(name, type, length):
	company.employeeName = name;
	company.employeeType = setEmployeeType(type);
	company.employeeLength = length;
	company.employeeVacation = calcEmployeeVacation(company.employeeType, company.employeeLength);

# Abbreviate the employee type
def setEmployeeType(type):
	return {
		"Full-time" : "[FT]",
		"Contractor" : "[C]",
		"Temporary" : "[T]"
	} [type]

# Calculate amount of vacation time accrued by employee
def calcEmployeeVacation(type, length):
	vacaPerYear = 5;
	if (type == "[FT]"):
		return int(length) * vacaPerYear;
	else:
		return None;

# Print full employee information
def printEmployeeInfo():
	print ("Name: " + company.employeeName + company.employeeType + ", Duration: " + str(company.employeeLength) + " years, Vacation Accrued: " + str(company.employeeVacation) + " days.");

# Output
create("Fred Johnson", "Full-time", 1.5);
printEmployeeInfo();

create("Jane James", "Contractor", 0.8);
printEmployeeInfo();

create("Tony Tiger", "Temporary", 1.75);
printEmployeeInfo();
