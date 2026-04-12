while True:
    s = input()
    if s == '#':
        break
    else:
        a, b, c, d = map(int, input().split())
        s_list = s.split('/')
        a_str = ''
        if a == c:
            for i in s_list[a-1]:
                if i == 'b':
                    a_str += 'b'
                else:
                    a_str += '.' * int(i)
            a_tmp = a_str[min(b, d)-1]
            c_tmp = a_str[max(b, d)-1]
            a_rep = a_str[:min(b, d)-1] + c_tmp + a_str[min(b, d):max(b, d)-1] + a_tmp + a_str[max(b, d):]
            a_s = ''
            count = 0
            flag = 0
            for i in a_rep:
                if i == '.':
                    flag = 1
                    count += 1
                elif flag == 1:
                    a_s += str(count)
                    a_s += str('b')
                    flag = 0
                    count = 0
                else:
                    a_s += str('b')
                    flag = 0
                    count = 0
            if flag == 1:
                a_s += str(count)
                flag = 0
            s_list[a-1] = a_s
        else:
            for i in s_list[a-1]:
                if i == 'b':
                    a_str += 'b'
                else:
                    a_str += '.' * int(i)
            a_tmp = a_str[b-1]
            c_str = ''
            for i in s_list[c-1]:
                if i == 'b':
                    c_str += 'b'
                else:
                    c_str += '.' * int(i)
            c_tmp = c_str[d-1]
            a_rep = a_str[:b-1] + c_tmp + a_str[b:]
            c_rep = c_str[:d-1] + a_tmp + c_str[d:]
            flag = 0
            count = 0
            a_s = ''
            for i in a_rep:
                if i == '.':
                    flag = 1
                    count += 1
                elif flag == 1:
                    a_s += str(count)
                    a_s += str('b')
                    flag = 0
                    count = 0
                else:
                    a_s += str('b')
                    flag = 0
                    count = 0
            if flag == 1:
                a_s += str(count)
                flag = 0
            count = 0
            c_s = ''
            for i in c_rep:
                if i == '.':
                    flag = 1
                    count += 1
                elif flag == 1:
                    c_s += str(count)
                    c_s += str('b')
                    flag = 0
                    count = 0
                else:
                    c_s += str('b')
                    flag = 0
                    count = 0
            if flag == 1:
                c_s += str(count)
            s_list[a-1] = a_s
            s_list[c-1] = c_s
        out = ''
        for i in range(len(s_list)):
            out += s_list[i]
            if i < len(s_list) - 1:
                out += '/'
        print(out)

