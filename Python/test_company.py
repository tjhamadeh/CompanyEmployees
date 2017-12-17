# Unit test for company.py
import unittest
import company

class TestCompany(unittest.TestCase):
	# Test if employee type is being properly set up
	def test_employee_FT(self):
		self.assertEqual(company.setEmployeeType("Full-time"), "[FT]");

	def test_employee_C(self):
		self.assertEqual(company.setEmployeeType("Contractor"), "[C]");

	def test_employee_T(self):
		self.assertEqual(company.setEmployeeType("Temporary"), "[T]");

	# Test if vacation time is properly being calculated based on the employee type and years at company.
	def test_vacation_FT(self):
		self.assertEqual(company.calcEmployeeVacation("[FT]", 1.5), 5);
		self.assertEqual(company.calcEmployeeVacation("[FT]", 2.5), 10);
		self.assertEqual(company.calcEmployeeVacation("[FT]", 0.8), 0);

	def test_vacation_C(self):
		self.assertEqual(company.calcEmployeeVacation("[C]", 0.8), None);
		self.assertEqual(company.calcEmployeeVacation("[C]", 1.8), None);
		self.assertEqual(company.calcEmployeeVacation("[C]", 2.1), None);

	def test_vacation_T(self):
		self.assertEqual(company.calcEmployeeVacation("[T]", 1.75), None);
		self.assertEqual(company.calcEmployeeVacation("[T]", 2.75), None);
		self.assertEqual(company.calcEmployeeVacation("[T]", 0.75), None);

# Allows us to run test with 'python ./test_company.py'
if __name__ == "__main__":
	unittest.main()
