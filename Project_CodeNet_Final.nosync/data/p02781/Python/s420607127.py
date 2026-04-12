import sys
from io import StringIO
import unittest
import os

# 再帰処理上限(dfs作成時に設定するのが面倒なので限度近い値を組み込む)
sys.setrecursionlimit(999999999)


# DPの対象配列の先頭に0を追加(先頭を0桁目、でなく1桁目、として可読性を上げる)
# さらに、入力を1文字ずつ分けて、数値型でリストに格納する。
def get_dp_target(string: str) -> []:
    return [0] + list(map(int, list(string)))


# 実装を行う関数
def resolve(test_def_name=""):
    try:
        # ※DP対象は以下の関数で取得※
        n = get_dp_target(input())

        target = int(input())

        # ---------------------------------
        # DP準備
        # ---------------------------------
        # DP配列作成※問題ごとに変える※
        dp = [[[0 for _ in range(101)] for _ in range(2)] for _ in range(len(n) + 1)]

        # DP準備(1桁目の設定)※0も処理するので1桁目の値+1回ループ
        for i in range(n[1] + 1):
            # 未満フラグ設定
            is_smaller = True if i < n[1] else False
            # ※問題ごとに変える※
            # dp[1][is_smaller][?] = ? というイメージは同じ。
            not_zero_count = 0 if i == 0 else 1
            dp[1][is_smaller][not_zero_count] += 1

        # ---------------------------------
        # DP(2桁目以降を処理する) ※ポイント：各ループの回数はDP配列の要素数と同じ。
        for place in range(2, len(n)):

            # 未満フラグの全パターンループ(2種類しかないが・・)
            for is_smaller in range(2):

                # 0以外の出現回数ループ(DPの兼ね合い上、範囲は0~100でOK)
                for not_zero_count in range(100):
                    # 値ループ
                    val_range = 10 if is_smaller else n[place] + 1
                    for val in range(val_range):
                        # 値によるフラグ変動
                        work_is_smaller = is_smaller or val < n[place]
                        work_not_zero_count = not_zero_count if val == 0 else not_zero_count + 1
                        dp[place][work_is_smaller][work_not_zero_count] += dp[place - 1][is_smaller][not_zero_count]

        print(dp[len(n) - 1][0][target] + dp[len(n) - 1][1][target])
    except IndexError as err:
        print("インデックスエラー:", err.args[0])


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
        test_input = """100
1"""
        output = """19"""
        self.assertIO(test_input, output)

    def test_input_2(self):
        test_input = """25
2"""
        output = """14"""
        self.assertIO(test_input, output)

    def test_input_3(self):
        test_input = """314159
2"""
        output = """937"""
        self.assertIO(test_input, output)

    def test_input_4(self):
        test_input = """9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
3"""
        output = """117879300"""
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
