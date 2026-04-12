A,B,C = list(map(str,input().split()))
ABC = int(A+B+C)
ans ="NO"
if ABC % 4 == 0:
  ans = "YES"
print(ans)