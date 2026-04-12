N = int(input())

# 二次元配列の初期化
# 0番目をaの出現回数、
# 1番目をbの出現回数とする
x = [[0 for i in range(26)] for j in range(N)]
#print(x)

for n in range(N):
    tmp=list(input())
    # 文字列をソートする
    tmp.sort()

    # 重複排除して、それぞれの文字が何回出現したかを数える
    tmp2 = set(tmp)
    for l in tmp2:
        #print(n, ord(l)-97,l,  tmp.count(l))
        x[n][ord(l)-97]= tmp.count(l)

ans  =[]
# a~zまで調べていき、全員最低1回以上出していれば、
# その文字は出力する。最低出現回数分連続させる。
for i in range(26):
    tmp3 = [row[i] for row in x]
    tmp4 = chr(97+i)* min(tmp3) if min(tmp3) != 0 else ""
    ans.append(tmp4)

print("".join(ans))
