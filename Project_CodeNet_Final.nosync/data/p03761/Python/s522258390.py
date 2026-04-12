from functools import reduce
import math

def main():
    # N! を求める
    # f = math.factorial(N)
    
    # 切り捨て
    # 4 // 3
    # 切り上げ
    #-(-4 // 3)
    
    # 初期値用:十分大きい数(100億)
    # 1e10

    # 初期値用:十分小さい数(-100億)
    # -1e10
    
    # 1文字のみを読み込み
    # 入力:2
    # a = input().rstrip()
    # 変数:a='2'
    
    # スペース区切りで標準入力を配列として読み込み
    # 入力:2 4 5 7
    # a, b, c, d = (int(_) for _ in input().split())  
    # 変数:a=2 b=4 c=5 d =7
    
    # 1文字ずつ標準入力を配列として読み込み
    # 入力:2 4 5 7
    # a = list(int(_) for _ in input().split())
    # 変数:a = [2, 4, 5, 7]    

    # 1文字ずつ標準入力を配列として読み込み
    # 入力:2457
    # a = list(int(_) for _ in input())
    # 変数:a = [2, 4, 5, 7]    
    N = int(input().rstrip())
    S = []
    ans = []
    min_len = 1e10
    min_i = 0
    for i in range(N):
        s = list(_ for _ in input())
        if(min_len>len(s)):
            min_len = len(s)
            min_i = i
        s.sort()
        S.append(s)
    for i in range(min_len):
        search_char = S[min_i][i]
        flag = True
        for j in range(N):
            if(search_char in S[j]):
                S[j][S[j].index(search_char)] = '0'
            else:
                flag=False
                break
        if flag:
            ans.append(search_char)
    print(''.join(ans))
    
if __name__ == '__main__':
    main()
