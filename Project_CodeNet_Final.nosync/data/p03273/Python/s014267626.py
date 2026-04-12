H,W=map(int,input().split())
L=[list(input()) for _ in range(H)]
L=[l for l in L if "#" in l]
#リストの中のリストで#を含まないリストは取り除く
LL=list(zip(*L))
#同じサブインデックスをもつ要素からなる配列を作る
LL=[l for l in LL if "#" in l]
L=list(zip(*LL))
for l in L:
  print("".join(l))