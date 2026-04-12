right = [chr(ord('a') + i) for i in range(7,16)]
right += ['u','y']

def check(a):
        if a in right:
                return "ri"
        else:
                return "le"

while True:
        a = input()
        if a == '#':
                break
        word = [c  for c in a]
        n = ""
        ans = 0
        for i,w in enumerate(word):
                if i == 0:
                        n = check(w)
                else:
                        if n != check(w):
                                ans += 1
                                n = check(w)
        print(ans)
        


