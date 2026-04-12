from collections import Counter
n = int(input())
s = [dict(Counter(list(input()))) for _ in range(n)]
st = []
kouho = s[0]
moji = sorted(kouho)
for i in moji: #１つめの辞書から１つ１つ取り出す
    mn = kouho[i]
    for j in s: #すべての辞書において確認
        if i in j: #もし辞書に入っているのであれば取る値の小さいほうをmnに格納
            mn = min(mn,j[i])
        else:
            mn = 0
    st.append(i*mn)

print(''.join(st))