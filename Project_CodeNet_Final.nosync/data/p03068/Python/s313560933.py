n=int(input())  #数値入力
s=input()
k=int(input())  #数値入力

print(''.join([x if x == s[k-1] else '*' for x in list(s)]))