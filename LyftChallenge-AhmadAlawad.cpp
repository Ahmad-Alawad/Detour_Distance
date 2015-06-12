/* I wrote a complete code including main fumction
	The test data I used:
				Latitude	Longtitude		Address
				---------	-----------		----------
			A:	37.643861	-122.427852		358 Alida way, south san francisco, ca
			B:	37.611749	-122.402334		1500 elcamino real, san bruno, ca
			C:	37.621548	-122.408184		277 carlton ave, san bruno, ca
			D:	37.621313	-122.378955		San Francisco Airport
*/

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

const double pi=3.14159265358979323846;

//This function converts decimal degrees to radians
double deg2rad(double deg)
{
	return (deg * pi / 180);
}

//This function converts radians to decimal degrees 

double rad2deg(double rad)
{
	return (rad * 180 / pi);
}

//This function calculates the distance between any two points
double distance(double lat1, double lon1, double lat2, double lon2)
{
	double theta, dist;
	theta = lon1 - lon2;
	dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
	dist = acos(dist);
	dist = rad2deg(dist);
	dist = dist * 60 * 1.1515;
	return (dist);
}

int main()
{
	double latitudeA, latitudeB, latitudeC, latitudeD, longtitudeA, longtitudeB, longtitudeC, longtitudeD, distanceAB, distanceAC, distanceCD, distanceDB, totalDistance;
	cout<<"latitudeA: ";
	cin>>latitudeA;
	cout<<"longtitudeA: ";
	cin>>longtitudeA;
	cout<<"latitudeB: ";
	cin>>latitudeB;
	cout<<"longtitudeB: ";
	cin>>longtitudeB;
	cout<<"latitudeC: ";
	cin>>latitudeC;
	cout<<"longtitudeC: ";
	cin>>longtitudeC;
	cout<<"latitudeD: ";
	cin>>latitudeD;
	cout<<"longtitudeD: ";
	cin>>longtitudeD;

	distanceAB = distance(latitudeA, longtitudeA, latitudeB, longtitudeB);
	distanceAC = distance(latitudeA, longtitudeA, latitudeC, longtitudeC);
	distanceCD = distance(latitudeC, longtitudeC, latitudeD, longtitudeD);
	distanceDB = distance(latitudeD, longtitudeD, latitudeB, longtitudeB);

	totalDistance = distanceAC + distanceCD + distanceDB;
	
	cout<<"Distance between A and C is "<<distanceAC<<endl;
	cout<<"Distance between C and D is "<<distanceCD<<endl;
	cout<<"Distance between D and B is "<<distanceDB<<endl;
	cout<<"Whole distance travelled from A to B including the detour is "<<totalDistance<<endl;
	cout<<"Detour Distance between the original trip and the added trip is "<<totalDistance-distanceAB<<endl; 
	return 0;
}
