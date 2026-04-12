A,B,C = map(str,input().split())
res = int(A+B+C)
if res % 4 == 0:
	  print("YES")
else:
    print("NO")