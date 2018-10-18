#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool leap_year(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year%400==0);
}

// Функция возращает true, если дата корректна, иначе - false.
bool date_correctness(int day, int month, int year) {
	if ((year <= 0) || (day <= 0) || (month <= 0)) {
		return false;
	}
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (day <= 31) {
			return true;
		}
		return false;
	case 2:
	 	if (leap_year(year) && day <= 29) {
			return true;
		}
		if (day <= 28) {
			return true;
		}
		return false;
	case 4: case 6: case 9: case 11:
		if (day <= 30) {
			return true;
		}
		return false;
	default:
		return false;
	}
}


void test_date_correctness() {
    assert(date_correctness(1,1,2018));
    assert(date_correctness(30,5,1999));
    assert(date_correctness(31,12,100));
    assert(date_correctness(31,8,2016));
    assert(date_correctness(29,2,2400));
    assert(!date_correctness(31,4,3000));
    assert(!date_correctness(-1,3,1));
    assert(!date_correctness(1,-3,1));
    assert(!date_correctness(1,3,-1));
    assert(!date_correctness(2,13,2001));
    assert(!date_correctness(40,5,777));
    assert(!date_correctness(29,2,1900));

    printf("Тесты прошли успешно!\n");
}

int main() {
    test_date_correctness();
    return 0;
}
