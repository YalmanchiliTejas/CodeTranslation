n, x, m = (int(x) for x in input().split())
dic = {}
count = 1
dic[x]=0
ans = [x]
bool = True
while (count < n):
    x = pow(x, 2, m)
    if x not in dic:
        dic[x] = count
        ans.append(x)
    else:
        roop = ans[dic[x]:count]
        ans = sum(ans[:dic[x]])
        roop_count = (n-dic[x])//len(roop)
        roop_hasuu = (n-dic[x])%len(roop)
        ans+=roop_count*sum(roop)+sum(roop[:roop_hasuu])
        print(ans)
        bool = False
        count = pow(10, 13)
    count+=1
if bool:
    print(sum(ans))
