if __name__ == '__main__':
    while 1:
        line = input()
        if line == '#':break
        right = ['q','a','z','w','s','x','e','d','c','r','f','v','t','g','b']
        left = ['y','h','n','u','j','m','i','k','o','l','p']
        ans = 0
        if line[0] in left:current ,other= left,right
        else:current,other = right,left
        for moji in line:
            if  not moji in current:
                ans +=1
                current ,other= other,current
            else: pass
        print(ans)