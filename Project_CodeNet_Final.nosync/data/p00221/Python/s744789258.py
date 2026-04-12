while 1:
        n = map(int,raw_input().split())
        if n[0] == n[1] == 0:
                break
        m, o = [1 for x in range(n[0])], 0

        for x in range(1,n[1]+1):
                a = raw_input()
                if sum(m) == 1:
                        pass
                elif x % 15 == 0:
                        if a != "FizzBuzz":
                                m[o] = 0
                elif x % 3 == 0:
                        if a != "Fizz":
                                m[o] = 0
                elif x % 5 == 0:
                        if a != "Buzz":
                                m[o] = 0
                else:
                        if a != str(x):
                                m[o] = 0
                while 1:
                        o += 1
                        if sum(m) == 1:
                                break
                        elif o == len(m):
                                o = -1
                        elif m[o] == 1:
                                break

        OutPut = ""
        for x in range(n[0]):
                if m[x] == 1:
                        OutPut += str(x+1) + " "
        print OutPut[:-1]