A,B,C,X,Y = map(int,input().split())
ABset = min(A+B,2*C)
Asgl = min(A,2*C)
Bsgl = min(B,2*C)
Z = min(X,Y)
Ans = ABset * Z
Ans += Asgl * (X - Z)
Ans += Bsgl * (Y - Z)
print(Ans)