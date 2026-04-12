import numpy as np

H,W=list(map(int,input().split(" ")))
A=np.full((H,W),".",np.str)

# 入力を格納
for h in range(H):
    A[h,:]=list(input())

# 各行について
for h in reversed(range(H)):
    if (A[h,:]==".").all()==True: # 全ての要素が"."の場合行を削除
        A=np.delete(A,h,axis=0)

# 各列について
for w in reversed(range(A.shape[1])):
    if (A[:,w]==".").all()==True: # 全ての要素が"."の場合列を削除
        A=np.delete(A,w,axis=1)

# 出力
for a in A:
    print("".join(a))