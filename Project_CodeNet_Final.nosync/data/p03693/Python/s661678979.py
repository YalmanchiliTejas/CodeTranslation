#print(int(input())+int(input()))
a = map(str,input().split())
ls = []
sm = ""
for i in a:
    sm += i
nm = int(sm)
if nm%4==0:
    print("YES")
else:
    print("NO")