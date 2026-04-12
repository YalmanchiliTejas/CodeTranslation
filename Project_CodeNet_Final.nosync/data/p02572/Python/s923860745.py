n = int(input())
temparr = input()
temparr = temparr.split()
arr = []
for i in temparr:
    arr.append(int(i)  % 1000000007)
    
ans = 0 
total = []
curtotal = sum(arr)
total.append(curtotal)
for i in range(n):
    curtotal -= arr[i]
    total.append(curtotal)
for i in range(n):
    total[i] = total[i] % 1000000007

for i in range(n - 1):
    curnum = arr[i]
    tempans = curnum * total[i + 1]
    if tempans >= 1000000007:
        tempans = tempans % 1000000007
    ans += tempans

if ans >= 1000000007:
    print(ans % 1000000007)
else:
    print(ans)