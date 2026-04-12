n = input()
K = int(input())
len_n = len(n)
ans = 0
#自由な数字を選んでいいのかどうか？、今使った0以外、今の桁数
def calc(free, count, now):
    global ans
    if count == K:
        ans += 1
        return
    if now == len_n:
        return 
    if free:
        for _ in range(9):
            calc(free, count + 1, now+1)
        #この数字を0にするとき
        calc(free, count, now+1)
    else:
        #自由に数字選べない時
        if n[now] != '0':
            for _ in range(int(n[now])-1):
                calc(not free, count + 1, now+1)
            #この数字を元の数字と同じ
            calc(free, count+1, now+1)
        #このすうじを0にする
            calc(not free, count, now+1)
        else:
            calc(free, count, now+1)
calc(False,0,0)
print(ans)