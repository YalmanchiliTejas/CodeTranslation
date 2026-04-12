while 1:
    s = str(input())
    if s == "#":
        break
    cnt = 0
    left = ["q","w","e","r","t","a","s","d","f","g","z","x","c","v","b"]
    right = ["y","u","i","o","p","h","j","k","l","n","m"]
    if s[0] in left:
        now = "left"
    elif s[0] in right:
        now = "right"
    for i in range(len(s)):
        if  s[i] in left:
            if now != "left":
                cnt += 1
                now = "left"
        elif s[i] in right:
            if now != "right":
                cnt += 1
                now = "right"
    print(cnt)
