from math import factorial
def combination(n, r):
    return factorial(n)//(factorial(n-r) * factorial(r))

def answer(n,k):
    ans = 0
    if k>1:
        if n=='':
            return 0
        # 先頭が0の時
        if n[0]=='0':
            ans += answer(n[1:],k)
        else:
            # 先頭以外で3つ使う
            if len(n)>k:
                ans += combination(len(n)-1,k)*9**k
            # 先頭で一つ使うが、先頭はNの先頭より小さい
            if len(n)>k-1:
                ans += (int(n[0])-1)*combination(len(n)-1,k-1)*9**(k-1)
            # 先頭で、Nの先頭と同じ数を使う
            ans += answer(n[1:],k-1)
    else:
        if n=='':
            return 0
        if n[0]=='0':
            ans += answer(n[1:],k)
        else:
            if len(n)>1:
                ans += combination(len(n)-1,1)*9
            ans += int(n[0])
    return ans

n = input()
k = int(input())

print(answer(n,k) if len(n)>=k else 0)