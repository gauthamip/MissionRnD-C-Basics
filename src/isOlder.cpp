/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2) {
	int dd1, mm1, yy1;
	int dd2, mm2, yy2;
	dd1 = (dob1[0] - '0') * 10 + dob1[1] - '0';
	mm1 = (dob1[3] - '0') * 10 + dob1[4] - '0';
	yy1 = (dob1[6] - '0') * 1000 + (dob1[7] - '0') * 100 + (dob1[8] - '0') * 10 + dob1[9] - '0';
	dd2 = (dob2[0] - '0') * 10 + dob2[1] - '0';
	mm2 = (dob2[3] - '0') * 10 + dob2[4] - '0';
	yy2 = (dob2[6] - '0') * 1000 + (dob2[7] - '0') * 100 + (dob2[8] - '0') * 10 + dob2[9] - '0';
	if (dd1 < 0 || dd2 < 0 || mm1 < 0 || mm2 < 0 || yy1 < 0 || yy2 < 0 || mm1>12 || mm2>12)
		return -1;
	else if ((mm1 == 1 || mm1 == 3 || mm1 == 5 || mm1 == 7 || mm1 == 9 || mm1 == 11) && (dd1>30))
		return -1;
	else if ((mm1 == 4 || mm1 == 6 || mm1 == 8 || mm1 == 10 || mm1 == 12) && dd1>31)
		return -1;
	else if (mm1 == 2 && yy1 % 4 == 0 && dd1 > 29)
		return -1;
	else if (mm1 == 2 && yy1 % 4 != 0 && dd1>28)
		return -1;
	else if ((mm2 == 1 || mm2 == 3 || mm2 == 5 || mm2 == 7 || mm2 == 9 || mm2 == 11) && (dd2>30))
		return -1;
	else if ((mm2 == 4 || mm2 == 6 || mm2 == 8 || mm2 == 10 || mm2 == 12) && dd2>31)
		return -1;
	else if (mm2 == 2 && yy2 % 4 == 0 && dd2 > 29)
		return -1;
	else if (mm2 == 2 && yy2 % 4 != 0 && dd2>28)
		return -1;
	else if (yy1 > yy2)
		return 2;
	else if (yy1<yy2)
		return 1;
	else if (yy1 == yy2 && mm1>mm2)
		return 2;
	else if (yy1 == yy2 && mm1 < mm2)
		return 1;
	else if (yy1 == yy2 && mm1 == mm2 && dd1>dd2)
		return 2;
	else if (yy1 == yy2 && mm1 == mm2 && dd1 < dd2)
		return 1;
	else
		return 0;
}



