# Your code here!
def pin(type=int):
    return map(type,input().split())
"""    
入力は以下の形式で標準入力から与えられる。

N  #これいるかなぁ
x1　y1 N=0として。
xN　yN
"""
N,M= pin()
if N==M:
    print("Yes")
else:
    print("No")