from collections import Counter
N = int(input())

S = [input() for _ in range(N)]

ctr = Counter(S[0]) # 引数で渡したリストとかタプルの中にOOが何個みたいな形のオブジェクトを生成
for s in S[1:]:
    ctr &= Counter(s) #論理積をとって、同じ部分だけ残していく

ans = ""
for k,v in sorted(ctr.items()):
    ans += k*v

print(ans)