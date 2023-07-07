#include <iostream>
#include <math.h>
#include <random>

int main() {
	int no_of_points, points_in_circle;
	std::cout << "Please enter the number of points you would like to \
use for the Monte Carlo simulation: ";
	std::cin >> no_of_points;

	points_in_circle = 0;

	//Initialise random num generator
	std::default_random_engine generator;

	//Uniform distribution
	std::uniform_real_distribution<double> distribution(0.0, 1.0);

	double x, y;
	


	/*Using a unit circle circumscribed inside of unit square
	with the circle centred on (0.5,0.5)*/

	for (int i = 0; i < no_of_points; i++) {
		x = distribution(generator);
		y = distribution(generator);

		double distance_from_origin;
		distance_from_origin = sqrt(pow(x - 0.5, 2) + pow(y - 0.5, 2));
		
		if (distance_from_origin <= 0.5) {
			points_in_circle++;
		}

	}

	double pi_estimate;
	pi_estimate = 4.0 * points_in_circle / no_of_points;

	std::cout << "The estimate of pi using " << no_of_points << " trials is " << pi_estimate;

	return 0;
}