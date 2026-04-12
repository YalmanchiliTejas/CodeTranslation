import sys
from io import StringIO
import unittest
import os

# 再帰処理上限(dfs作成時に設定するのが面倒なので限度近い値を組み込む)
sys.setrecursionlimit(999999999)


# 実装を行う関数
def resolve(test_def_name=""):
    # 数値取得サンプル
    n = int(input())
    a_s = list(map(int, input().split()))

    # 和
    aaa = sum(a_s)

    ans = 0
    for cnt, a in enumerate(a_s):
        aaa -= a
        if aaa == 0:
            break

        ans += aaa * a
        ans = ans % (pow(10, 9) + 7)

    print(ans % (pow(10, 9) + 7))

    # テストクラス


class TestClass(unittest.TestCase):
    def assertIO(self, assert_input, output):
        stdout, sat_in = sys.stdout, sys.stdin
        sys.stdout, sys.stdin = StringIO(), StringIO(assert_input)
        resolve(sys._getframe().f_back.f_code.co_name)
        sys.stdout.seek(0)
        out = sys.stdout.read()[:-1]
        sys.stdout, sys.stdin = stdout, sat_in
        self.assertEqual(out, output)

    def test_input_1(self):
        test_input = """3
1 2 3"""
        output = """11"""
        self.assertIO(test_input, output)

    def test_input_2(self):
        test_input = """4
141421356 17320508 22360679 244949"""
        output = """437235829"""
        self.assertIO(test_input, output)

    # 自作テストパターン
    def test_original(self):
        pass


# 実装orテストの呼び出し
if __name__ == "__main__":
    if os.environ.get("USERNAME") is None:
        # AtCoder提出時の場合
        resolve()

    else:
        # 自PCの場合
        unittest.main()
