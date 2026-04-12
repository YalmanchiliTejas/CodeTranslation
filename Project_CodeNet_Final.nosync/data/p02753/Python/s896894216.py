A=list(input())
A.sort()#sortメソッドは破壊的
print("No" if A[1]==A[2]==A[0] else "Yes")
