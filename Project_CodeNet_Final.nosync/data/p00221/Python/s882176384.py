while True:
    M, N = map(int, raw_input().split())
    if M == N == 0: break
    m = [i for i in range(1, M+1)]
    index = 0
    num = 1
    for i in range(N):
        if len(m) != 1:
            line = raw_input()
            flag = False
            if num % 15 == 0:
                if line != 'FizzBuzz':
                    del m[index]
                    flag = True
            elif num % 3 == 0:
                if line != 'Fizz':
                    del m[index]
                    flag = True
            elif num % 5 == 0:
                if line != 'Buzz':
                    del m[index]
                    flag = True
            else:
                if not line.isdigit():
                    del m[index]
                    flag = True
                else:
                    if int(line) != num:
                        del m[index]
                        flag = True
            if not flag:
                index += 1
            if index+1 > len(m):
                index = 0
            num += 1
        else:
            raw_input()
    else:
        print ' '.join(map(str, m))