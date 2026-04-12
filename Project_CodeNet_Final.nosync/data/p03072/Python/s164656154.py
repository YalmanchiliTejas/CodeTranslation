"""
B - Great Ocean View
https://atcoder.jp/contests/abc124/tasks/abc124_b
"""
if __name__ == '__main__':
    input_list = list(map(int, input().split()))
    N = input_list
    input_list = list(map(int, input().split()))
    H_list = input_list

    H1 = H_list[0]
    answer = 1
    for i, Hi in enumerate(H_list):
        if i == 0:
            continue
        else:
            west_H_list = H_list[0:i]
            max_h_west = sorted(west_H_list, reverse=True)[0]
            if max_h_west <= Hi:
                answer += 1

    print(answer)