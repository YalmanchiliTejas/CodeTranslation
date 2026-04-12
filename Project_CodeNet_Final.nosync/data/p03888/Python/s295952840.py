from fractions import *
r1,r2=map(int,input().split())
R1=Fraction(1,r1)
R2=Fraction(1,r2)
R3=R1+R2
print(R3.denominator/R3.numerator)