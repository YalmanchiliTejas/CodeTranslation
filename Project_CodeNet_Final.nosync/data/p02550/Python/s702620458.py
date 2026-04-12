N,X,M=map(int,input().split())
ans=[X]
flag=0
for n in range(N):
    a=ans[-1]**2%M
    if a in ans:
        num=n
        flag=1
        break
    ans.append(a)
if flag==0:
    print(sum(ans[:-1]))
else:
    first = ans.index(a)
    if num==first:
        answer=sum(ans[:-1])+a*(N-num)
        print(answer)
    else:

        nums = ans[first:]
        rest = N - num
        answer = sum(ans)
        kaisuu = rest // (num - first + 1)
        answer += sum(nums) * kaisuu
        nokori = rest - kaisuu * (num - first + 1)
        answer += sum(nums[:nokori - 1])
        print(answer)
        