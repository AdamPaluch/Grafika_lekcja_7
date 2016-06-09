#pragma once

#include <iostream>

union CVector
{
	struct{
		float x, y, z;
	};
	float vectors[3];
};

void SetZero(CVector &v)
{
	v.x = 0.0f;
	v.y = 0.0f;
	v.z = 0.0f;
}

float Len(CVector &v)
{
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

void Normalize(CVector &v)
{
	float len = Len(v);
	v.x /= len;
	v.y /= len;
	v.z /= len;
}

float Dot(CVector &a, CVector &b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

CVector Cross(CVector &a, CVector &b)
{
	CVector v;
	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;
	return v;
}

CVector Sub(CVector &a, CVector &b)
{
	CVector v;
	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return v;
}

CVector Add(CVector &a, CVector &b)
{
	CVector v;
	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return v;
}

CVector SetVec(float x, float y, float z)
{
	CVector v;
	v.x = x;
	v.y = y;
	v.z = z;

	return v;
}

void DispVec(CVector &v)
{
	std::cout << "(" << v.x << "," << v.y << "," << v.z << ")" << std::endl;
}

/*
B is the middle point, A and C are the arms.
		B
		/\
	   /--\
	  /    \
	  A     C
*/
CVector GetNormalFromPoints(CVector &pA, CVector &pB, CVector &pC)
{
	CVector v1 = Sub(pA, pB);
	CVector v2 = Sub(pC, pB);
	CVector n = Cross(v1, v2);
	Normalize(n);
	return n;
}

CVector GetNormalFromVectors(CVector &v1, CVector &v2)
{
	CVector n = Cross(v1, v2);
	Normalize(n);
	return n;
}