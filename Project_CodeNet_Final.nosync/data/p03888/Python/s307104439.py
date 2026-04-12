a,b = map(int,input().split())
# (R1)+(R2)/(R1*R2) = 1/(R3)
# (R1)+(R2)*(R3) = (R1*R2)
# (R3) = (R1*R2)/(R1)+(R2)
S = a+b
print(float((a*b)/S))