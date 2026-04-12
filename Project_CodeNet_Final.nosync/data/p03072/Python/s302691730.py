N = int(input())
Hn = list(map(int, input().split()))
count = 0
for num, i in enumerate(Hn[1:]):
    if(max(Hn[:num+1]) <= i):
        count += 1
print(count + 1)