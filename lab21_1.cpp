#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect R1, Rect R2){
	double p1 = R1.x, q1 = R1.y, x1 = R2.x, y1 = R2.y;
	double p2 = p1+R1.w, q2 = q1-R1.h;
	double x2 = x1+R2.w, y2 = y1-R2.h;
	if (!((p1 < x2) && (q1 > y2) && (p2 > x1) && (q2 < y1))) return 0;
	else{
		double left = max(x1,p1);
		double right = min(x2,p2);
		double top = min(y1,q1);
		double bottom = max(y2,q2);

		double w = right-left;
		double h = top-bottom;

		return w*h;
	}
}
