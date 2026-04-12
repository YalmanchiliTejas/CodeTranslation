

def main():
    num = int(input())
    data_list = [int(input()) for i in range(num)]
    data_list.sort()


    if num % 2 == 1:
        hikukazu = 0
        for i in range(num // 2 + 1):
            hikukazu += 2 * data_list[i]
        hikukazu -= data_list[num // 2] + data_list[num // 2 - 1]

        tasukazu = 0
        for i in range(num // 2 + 1, num):
            tasukazu += 2 * data_list[i]
    else:
        hikukazu = 0
        for i in range(num // 2):
            hikukazu += 2 * data_list[i]
        hikukazu -= data_list[num // 2 - 1]

        tasukazu = 0
        for i in range(num // 2, num):
            tasukazu += 2 * data_list[i]
        tasukazu -= data_list[num // 2]

    a = tasukazu - hikukazu

    if num % 2 == 1:
        hikukazu = 0
        for i in range(num // 2):
            hikukazu += 2 * data_list[i]

        tasukazu = 0
        for i in range(num // 2, num):
            tasukazu += 2 * data_list[i]
        tasukazu -= data_list[num // 2] + data_list[num // 2 + 1]
    else:
        hikukazu = 0
        for i in range(num // 2):
            hikukazu += 2 * data_list[i]
        hikukazu -= data_list[num // 2 - 1]

        tasukazu = 0
        for i in range(num // 2, num):
            tasukazu += 2 * data_list[i]
        tasukazu -= data_list[num // 2]

    b = tasukazu - hikukazu

    # print(a, b)
    print(max(a, b))


if __name__ == '__main__':
    main()