#include "pch.h"

// Fixture for testing CompanyClass
struct CompanyTest : testing::Test
{
	CompanyClass *company;
	CompanyTest()
	{
		company = new CompanyClass;
	}
	~CompanyTest()
	{
		delete company;
	}
};

// Test if setting and getting of name works
TEST_F(CompanyTest, EmployeeNameTest)
{
	// Set employee name as Fred Johnson
	company->setEmployeeName("Barney Rubble");
	ASSERT_EQ("Barney Rubble", company->getEmployeeName());

	// Set employee name as Jane James
	company->setEmployeeName("Tony Tiger");
	ASSERT_EQ("Tony Tiger", company->getEmployeeName());
}

// Test if setting and getting of employee type works
TEST_F(CompanyTest, EmployeeTypeTest)
{
	// Set employee as full-time
	company->setEmployeeType(FULLTIME);
	ASSERT_EQ("[FT]", company->getEmployeeType());

	// Set employee as contractor
	company->setEmployeeType(CONTRACTOR);
	ASSERT_EQ("[C]", company->getEmployeeType());

	// Set employee as temporary
	company->setEmployeeType(TEMPORARY);
	ASSERT_EQ("[T]", company->getEmployeeType());
}

// Test if setting and getting employee duration with company works
TEST_F(CompanyTest, EmployeeDurationTest)
{
	company->setEmployeeDuration(2.0);
	EXPECT_EQ(2.0, company->getEmployeeDuration());

	company->setEmployeeDuration(1.5);
	EXPECT_EQ(1.5, company->getEmployeeDuration());
}

// Test if employee vacation is calculated correctly when setting employee duration
TEST_F(CompanyTest, EmployeeVacationTest)
{
	// First test as full-time employee
	EXPECT_EQ(10, company->calcEmployeeVacation(FULLTIME, 2.0));
	EXPECT_EQ(5, company->calcEmployeeVacation(FULLTIME, 1.5));

	// Set employee type to contractor
	EXPECT_EQ(0, company->calcEmployeeVacation(CONTRACTOR, 2.0));
	EXPECT_EQ(0, company->calcEmployeeVacation(CONTRACTOR, 1.5));

	// Set employee type to temporary
	EXPECT_EQ(0, company->calcEmployeeVacation(TEMPORARY, 2.0));
	EXPECT_EQ(0, company->calcEmployeeVacation(TEMPORARY, 1.5));
}

// Start program
int main(int argc, char* argv[])
{
	// Run google unit tests
	testing::InitGoogleTest(&argc, argv);

	// Print all values
	CompanyClass *companyFred = new CompanyClass("Barney Rubble", FULLTIME, 1.5);
	companyFred->printEmployeeInfo();

	CompanyClass *companyJane = new CompanyClass("Tony Tiger", CONTRACTOR, 0.8);
	companyJane->printEmployeeInfo();

	CompanyClass *companyTony = new CompanyClass("Yogi Bear", TEMPORARY, 1.75);
	companyTony->printEmployeeInfo();

	std::cin.get();
	return RUN_ALL_TESTS();
}
