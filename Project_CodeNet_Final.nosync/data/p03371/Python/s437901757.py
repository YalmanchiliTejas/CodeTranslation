A,B,C,X,Y=map(int,input().split())
print(min(A*X+B*Y,max(C*2*X+(Y-X)*B,C*2*Y+(X-Y)*A),C*max(2*X,2*Y)))