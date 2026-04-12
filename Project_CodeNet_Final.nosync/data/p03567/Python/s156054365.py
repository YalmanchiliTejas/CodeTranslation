# coding: utf-8
# 自分の得意な言語で
# Let's チャレンジ！！
if __name__ == '__main__':
    S = raw_input()
    flg = True
    for index in range(len(S) - 1):
        if S[index]+S[index+1] == 'AC':
            print 'Yes'
            flg = False
            break
    if flg:
        print 'No'
