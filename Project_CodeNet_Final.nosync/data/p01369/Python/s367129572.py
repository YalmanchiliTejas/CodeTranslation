#coding: utf-8

left = ['Q','W','E','R','T','A','S','D','F','G','Z','X','C','V','B']

while True: 
    s = str(raw_input())
    if s == '#':
        break
    else:
        s = s.upper()
        num = 0
        hand = ''
        for i in range(len(s)):
            if s[i] in left:
                if hand == 'right':
                    num = num + 1
                hand = 'left'
            else:
                if hand == 'left':
                    num = num + 1
                hand = 'right'
        print num