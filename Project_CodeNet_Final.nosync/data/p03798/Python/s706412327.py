n = int(input())
s = input()

# 0番目、1番目を決め打つ（４通り）ことで、連鎖的に次の種類を決めることができる
# 1番の証言通りに2番を決める, ..., N-1番目の証言通りに0番目を決める
# 最初に決めた0番目の種類と、最終的に導かれた0番目の種類が異なる場合、実現不可能
# 実現が可能な場合、0番目の証言が未検証なので検証する必要がある

# True:=羊, False:=狼　とする
# True/Falseで書くことで、not演算子での反転が使えて少し楽になる
for ptn in [[True, True], [True, False], [False, True], [False, False]]:
    # 1,2,...N-1番目の証言から2,3,...,N-1,0番目の種類を決める
    for i in range(1, n):
        if ptn[i] == True and s[i] == "o":
            ptn.append(ptn[i - 1])
        elif ptn[i] == True and s[i] == "x":
            ptn.append(not ptn[i - 1])
        elif ptn[i] == False and s[i] == "o":
            ptn.append(not ptn[i - 1])
        elif ptn[i] == False and s[i] == "x":
            ptn.append(ptn[i - 1])

    # 最初に決めた0番目の種類と、最終的に導かれた0番目の種類が等しい場合
    # 0番目の証言を検証する
    if ptn[0] == ptn[-1]:
        # 0番目に相当するものが重複しているので末尾の方を除いておく
        ptn.pop(-1)
        flag = False

        if ptn[0] == True and s[0] == "o":
            if ptn[-1] == ptn[1]:
                flag = True
        if ptn[0] == True and s[0] == "x":
            if ptn[-1] != ptn[1]:
                flag = True
        if ptn[0] == False and s[0] == "o":
            if ptn[-1] != ptn[1]:
                flag = True
        if ptn[0] == False and s[0] == "x":
            if ptn[-1] == ptn[1]:
                flag = True

        # 検証の結果、0番目の証言が矛盾しなかった場合、実現可能
        if flag == True:
            ans = []
            for i in range(n):
                if ptn[i] == True:
                    ans.append("S")
                elif ptn[i] == False:
                    ans.append("W")

            print("".join(ans))
            exit()

# 矛盾しないものが見つからなかった場合
print(-1)
