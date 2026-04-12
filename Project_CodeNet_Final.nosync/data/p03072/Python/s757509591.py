N = int(input())
H = list(map(int,input().split()))
s = 0
top = 0
for i in H:
    if i >= top:
        s += 1
        top = i
print(s)