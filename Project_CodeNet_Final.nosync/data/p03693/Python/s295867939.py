a, b, c = map(int, input().split())
num = 100 *a + 10*b + c
 
if num%4==0:
    print("YES")
else:
    print("NO")
