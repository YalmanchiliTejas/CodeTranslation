from math import factorial
def combination(n, r):
    return factorial(n)//(factorial(n-r) * factorial(r))

def answer(n,k):
    ans = 0
    # nが空の時
    if n=='':
        return 0
    # 先頭が0の時
    if n[0]=='0':
        ans += answer(n[1:],k)
    else:
        # 先頭以外でk個使う
        if len(n) > k:
            ans += combination(len(n)-1,k) * 9**k
        # 先頭でNの先頭より小さい数を1つ使う
        if len(n)>k-1:
            ans += (int(n[0])-1)*combination(len(n)-1,k-1)*9**(k-1)
        # 先頭でNの先頭と同じ数を使う
        if k>1:
            ans += answer(n[1:],k-1)
        else:
            ans += 1
    return ans

n = input()
k = int(input())

print(answer(n,k) if len(n)>=k else 0)