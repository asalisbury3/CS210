/*
Andrew Salisbury
Project One: Chada Tech Clock
Southern New Hampshire University
CS-210-H7011 Programming Languages 21EW3
January 20, 2021
*/


#include <iostream>
#include <string>
using namespace std;

//Variable declaration to be used for updating both clocks.
static int hour = 00;
static int minute = 00;
static int second = 00;

//Function governing 24/hr clock.
string
twentyFourHourClock ()
{
  string t4Hour;
  string t4Minute;
  string t4Second;


  //Add leading 0 to string if hour is less than ten.
  if (hour < 10)
    {
      t4Hour = "0" + to_string (hour);
    }
  else
    {
      t4Hour = to_string (hour);
    }

  if (minute < 10)
    {
      t4Minute = "0" + to_string (minute);
    }
  else
    {
      t4Minute = to_string (minute);
    }

  if (second < 10)
    {
      t4Second = "0" + to_string (second);
    }
  else
    {
      t4Second = to_string (second);
    }

  //Variable for formatting time.
  string currentTimeTwenty = t4Hour + ":" + t4Minute + ":" + t4Second;

  return currentTimeTwenty;
}

//Function governing standard clock.
string
twelveHourClock ()
{
  string postMeridiem;
  string standardHour;
  string standardMinute;
  string standardSecond;

  //For standard hour. Assigns either AM or PM, depening.
  if (hour < 10)
    {
      standardHour = "0" + to_string (hour);
    }
  else
    {
      standardHour = to_string (hour);
    }
  if (hour > 12)
    {
      standardHour = to_string (hour - 12);
      postMeridiem = "PM";

      if ((hour - 12) < 10)
	{
	  standardHour = "0" + to_string (hour - 12);
	}
    }
  else
    {
      postMeridiem = "AM";
    }

  // For standard minute
  if (minute < 10)
    {
      standardMinute = "0" + to_string (minute);
    }
  else
    {
      standardMinute = to_string (minute);
    }

  //For standard seconds.
  if (second < 10)
    {
      standardSecond = "0" + to_string (second);
    }
  else
    {
      standardSecond = to_string (second);
    }

  //Formatting standard time.
  string currentTimeTwelve =
    standardHour + ":" + standardMinute + ":" + standardSecond + " " +
    postMeridiem;

  return currentTimeTwelve;
}

//Function for outputting a display for the clock to the console.
void
clockDisplay ()
{
  string clockBorder;
  clockBorder.resize (26, '*');

  cout << clockBorder << "    " << clockBorder << endl;
  cout << "*     12-Hour Clock      *" << "    ";
  cout << "*     24-Hour Clock      *" << endl;
  cout << "*       " << twelveHourClock () << "      *";
  cout << "    " << "*         " << twentyFourHourClock ();
  cout << "       *" << endl;
  cout << clockBorder << "    " << clockBorder << endl;
}

//Output of user menu.
void
userMenu ()
{
  string menuBorder;
  menuBorder.resize (28, '*');

  cout << menuBorder << endl;
  cout << "* 1 - Add One Hour         *" << endl;
  cout << "* 2 - Add One Minute       *" << endl;
  cout << "* 3 - Add One Second       *" << endl;
  cout << "* 4 - Exit Program         *" << endl;
  cout << menuBorder << endl;

}

//Function for adding hours.
void
addHour ()
{
  if (hour >= 23)
    {
      hour = -1;


    }
  else
    {

      hour = hour + 1;
    }
}

//Function for adding minutes.
void
addMinute ()
{
  if (minute >= 59)
    {
      minute = -1;
      addHour ();


    }
  else
    {

      minute = minute + 1;
    }
}

//Function for adding seconds.
void
addSecond ()
{
  if (second >= 59)
    {
      second = 00;
      addMinute ();


    }
  else
    {

      second = second + 1;
    }
}

//Function for looping through via user input.
int
main ()
{
  int userChoice;

  clockDisplay ();
  userMenu ();

  cin >> userChoice;

  while (userChoice)
    {

      switch (userChoice)
	{

	case 1:
	  addHour ();
	  break;

	case 2:
	  addMinute ();
	  break;

	case 3:
	  addSecond ();
	  break;

	case 4:
	  cout << "Exiting program.";
	  exit (1);
	  break;
	}


      if ((userChoice < 1) || (userChoice > 4))
	{

	  cout << "Please enter a valid choice: 1 through 4." << endl;
	}

      clockDisplay ();
      userMenu ();

      cin >> userChoice;
    }

  return 0;
}
