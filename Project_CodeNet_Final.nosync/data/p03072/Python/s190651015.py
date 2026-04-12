N=int(input())
H = list(map(int, input().split(" ")))

m=0
num = 0
for h in H:
    if h>=m:
        num +=1
        m=h

print(num)
