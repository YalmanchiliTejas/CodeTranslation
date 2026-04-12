a,b = map(int,input().split())
cnt = 0
for i in range(a):
    s = input()
    cnt += s.count("#")

if cnt == a+b-1:
    print("Possible")
else:
    print("Impossible")