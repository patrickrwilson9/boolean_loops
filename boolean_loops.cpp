/*****************************************************************************
 *AUTHOR  	 	: Patrick Wilson
 *PROJECT 		: Loops & Boolean Expressions
 *DATE	 		: 12/3/18
******************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/*****************************************************************************
 * Project : Loops & Boolean Expressions
 *----------------------------------------------------------------------------
 * This program informs the user of their acceptance status based on their
 * 		height and weight qualifications.
 *----------------------------------------------------------------------------
 * INPUT:
 * 	<The user will input their gender (M/F), their height (inches) and their
 * 		weight (pounds)>
 *
 * OUTPUT:
 * 	<This program will output a heading>
 *
 * 	<This program will output the acceptance status of the user, error checking
 * 		for valid gender, height, and weight inputs>
 *
 *  < This program will run until the exit value (X) is entered. Once X is
 *  	entered, this program will end & output the total number of candidate(s)
 *  	accepted, and the percent of accepted candidate(s)>
 *****************************************************************************/
int main()
{

	/*************************************************************************
	 * CONSTANTS
	 * -----------------------------------------------------------------------
	 * OUTPUT - USED FOR HEADING
	 * -----------------------------------------------------------------------
	 * PROGRAMMER : Programmer's Name
	 * LAB_NUM    : Lab Number (specific to this lab)
	 * LAB_NAME   : Titles of the Lab
	 *************************************************************************/

	const char PROGRAMMER[] = "Patrick Wilson";
	const int  LAB_NUM      = 4;
	const char LAB_NAME[]   = "Loops & Boolean Expressions";

	char gender;			// IN & OUT  - gender of the user
	int height;				// IN & OUT  - height of the user
	int weight;				// IN & OUT  - weight of the user
	int acceptedCandidates;	// IN & CALC - count for accepted candidates
	int totalCandidates;	// IN & OUT  - total number of users
	double percAccepted;	// IN & OUT  - percentage of users accepted
	bool invalidGender;		// IN & CALC - condition to error check for gender
	bool invalidHeight;		// IN & CALC - condition to error check for height
	bool invalidWeight;		// IN & CALC - condition to error check for weight
	bool acceptableHeight;	// IN & OUT  - outputs ACCEPTED/REJECTED height
	bool acceptableWeight;	// IN & OUT  - outputs ACCEPTED/REJECTED weight

	bool entered;

	//OUTPUT - Heading
	cout << left;
	cout << "**************************************************\n";
	cout << "*  PROGRAMMED BY : "  << PROGRAMMER    << endl;
	cout << "*  PROJECT #" << setw(5) << LAB_NUM << ": " << LAB_NAME << endl;
	cout << setw(17) << "*  DATE"  << ": " << "12/3/18" << endl;
	cout << "**************************************************\n\n";
	cout << right;

	/*************************************************************************
	 * INPUT -<The user inputs their gender (M/F), their height (inches) and
	 * 				their weight (pounds)>
	 *************************************************************************/

	cout << "Please enter the candidate's information "
			"(enter 'X' to exit).\n";

	do //error check for a valid gender entry
	{
		cout << "Gender: "; //input gender
		cin.get(gender);
		cin.ignore(10000, '\n');

		invalidGender   = gender != 'm' && gender != 'M' &&
						  gender != 'f' && gender != 'F' &&
						  gender != 'x' && gender != 'X';

		totalCandidates = 0;

		if (invalidGender)
		{
			cout << "***** Invalid gender; please enter M or F *****\n";
		}
	} while (invalidGender);

	acceptedCandidates = 0;
	percAccepted = 0;
	entered = false;

	while (gender != 'X' && gender != 'x')
	{
		entered = true;

		do //error check for a height entry
		{
			cout << "Height: "; //input int height
			cin  >> (height);
			cin.ignore(10000, '\n');

			invalidHeight = height < 24 || height > 110;

			if (invalidHeight)
			{
				cout << "***** Invalid height; please enter a height in inches "
						"between 24 and 110. *****\n";
			}
		} while (invalidHeight);


		do //error check for a weight entry
		{
			cout << "Weight: "; //input int weight
			cin  >> (weight);
			cin.ignore(10000, '\n');

			invalidWeight = weight < 50 || weight > 1400;

			if (invalidWeight)
			{
				cout << "***** Invalid weight; please enter a weight in lbs "
						"between 50 and 1400. *****\n";
			}
		} while (invalidWeight);

	/*************************************************************************
	 * 	OUTPUT -
	 *	<This program will output a heading>
	 *
	 * 	<This program will output the acceptance status of the user, error
	 * 		checking for valid gender, height, and weight inputs>
	 *
	 *  <This program will run until the exit value (X) is entered. Once X is
	 *  	entered, this program will end & output the total number of
	 *  	candidate(s) accepted, and the percent of accpeted candidate(s)>
	 *************************************************************************/

		//height requirement for male and female
		acceptableHeight = 	(((gender == 'm' || gender == 'M') &&
							(height >= 65 && height <= 80)) ||
							((gender == 'f' || gender == 'F') &&
							(height >= 62 && height <= 75)));

		//weight requirement for male and female
		acceptableWeight = 	(((gender == 'm' || gender == 'M') &&
							(weight >= 130 && weight <= 250)) ||
						    ((gender == 'f' || gender == 'F') &&
						    (weight >= 110 && weight <= 185)));

		//checks for the specified height and weight requirements
		cout << endl << endl;
		cout << "This candidate has been ";
		cout << (!acceptableHeight && !acceptableWeight ?
				"rejected based on the HEIGHT and WEIGHT requirements."
				"\n\n\n\n" :
				(!acceptableHeight ?
				"rejected based on the HEIGHT requirement.\n\n\n\n" :
				(!acceptableWeight ?
				"rejected based on the WEIGHT requirement.\n\n\n\n" :
				"ACCEPTED!\n\n\n\n")));

		//REinput gender
		cout << "Please enter the candidate's information "
					"(enter 'X' to exit).\n";

		do //error check for a valid gender entry
		{
			cout << "Gender: "; //input char gender
			cin.get(gender);
			cin.ignore(10000, '\n');

			invalidGender = gender != 'm' && gender != 'M' &&
							gender != 'f' && gender != 'F' &&
							gender != 'x' && gender != 'X';

			if (invalidGender)
			{
				cout << "***** Invalid gender; please enter M or F *****\n";
			}
		} while (invalidGender);

		// if successful test, add one to acceptedCandidates
		if (acceptableHeight && acceptableWeight)
		{
			++acceptedCandidates;
		}

		// add one to totalCandidates
		++totalCandidates;

	} //while (gender != 'X' && gender != 'x')

	/*************************************************************************
	 * PROCESSING - <calculate the percent of candidates accepted>
	 *************************************************************************/

	//calculate the percent of candidates accepted
	percAccepted = (double(acceptedCandidates) / double(totalCandidates) * 100);

	//checks to see if a test has been done

	if (entered)
	{
	cout << endl << endl;
	cout << acceptedCandidates   << " candidates(s) accepted!"        << endl;
	cout << "That's " << setprecision(2) << percAccepted << "%" <<"!" << endl;
	}



	return 0;
}