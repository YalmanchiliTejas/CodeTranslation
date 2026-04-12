n = input()
h = list(map(int, input().split()))
count = 1


for i in range(int(n)):
    ok = 0
    if i!=0:
        for j in range(i):

            if h[j]<=h[i]:
                ok +=1
            if ok == i:
                count +=1

print(count)
