import itertools
n=int(input())
a= list(map(int, input().split()))

# aを偶数奇数の要素で振り分け
a1=[]
a2=[]

for i in range(n):
    if i%2==0:
        a1.append(a[i])
    else:
        a2.append(a[i])

# 累積和も作っておく
a3=list(itertools.accumulate(a1))
a4=list(itertools.accumulate(a2))


x1=sum(a1)
x2=sum(a2)


if n%2==0:
    ans=-float('inf')
    for i in range(n//2):
        ans=max(a3[i]+x2-a4[i],ans)
    print(max(ans,x1,x2))
else:
    # 奇数番目だけの要素を選んだ時の最大値
    ans1=sum(a1)-min(a1)
    # dp1[i]=奇数偶数奇数or偶数奇数と移動した時のi番目までのMAX
    dp1 = [-float('inf')] * (n // 2 + 1)
    dp1[0] = a1[0]
    # dp2[i]=奇数偶数or偶数のみと移動した時のi番目までのMAX
    dp2 = [-float('inf')] * (n // 2)
    dp2[0] = a2[0]
    for i in range(n // 2 - 1):
        dp2[i + 1] = max(a3[i] + a2[i + 1], dp2[i] + a2[i + 1])
        if i==0:
            dp1[i + 2] = dp2[i] + a1[i + 2]
        else:
            dp1[i + 2] = max(dp2[i] + a1[i + 2], dp1[i + 1] + a1[i + 2])
    print(max(dp1[-1], dp2[-1],ans1))