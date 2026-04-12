# 解説は動的計画法がわからなかった
# https://drken1215.hatenablog.com/entry/2019/06/15/202200 参照
# 可能なパターンの必要条件として、c=a-bとして、左右からcごとに取る,途中打ち切りも可
#「この必要条件が十分条件」(以下のl<rとなるrの最小値をaとする,n-1がcで割れたら例外)
n=int(input())
*s,=map(int, input().split())
n-=1
tmp=0
ans=0
for c in range(1,n+1):
    if n%c==0:
        l=0;r=n
        tmp=0
        while l<r:
            tmp+=s[l]+s[r]
            l+=c;r-=c
            ans=max(tmp,ans)###

        ans=max(tmp,ans)
    else:
        l=0;r=n
        tmp=0
        while l<n and r>c:
            tmp+=s[l]+s[r]
            l+=c;r-=c
            ans=max(tmp,ans)###

        ans=max(tmp,ans)
print(ans)