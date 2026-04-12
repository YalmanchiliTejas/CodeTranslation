n = input()
li = list(map(int,input().split()))
kotae = 0

for (i,x) in enumerate(li):
    for k in range(i+1):
        if x < li[k]:
            break
    else:
        kotae += 1
print(kotae)