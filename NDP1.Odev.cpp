/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSİ
**					202-2022 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI 1:
**				ÖĞRENCİ ADI.Halil TUFAN:
**				ÖĞRENCİ NUMARASI g211210027 :
**                         DERSİN ALINDIĞI GRUP. 2B :
****************************************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2.DÖNEM1.ÖDEV3
{
    //Statik class oluşturuldu
    static class Kelime
    {
        //statik değişkenler girildi
        static public int KücükHarfSayisi = 0;
        static public int BüyükHarfSayisi = 0;
        static public int RakamSayisi = 0;
        static public int SembolSayisi = 0;
        static public int SembolSayisi1 = 0;

        static public string Sifre;

        static public char[] SifreKarakterleri;

        static public int PuanSayici = 0;
        static public int Bosluksayisi = 0;

        //Girilen şifreyi metotla hafızaya alıp char dizisine eklendi
        public static void SifreOku()
        {
            Console.WriteLine("Lütfen Sifreyi Giriniz:");
            Sifre = Console.ReadLine();
            SifreKarakterleri = Sifre.ToCharArray();

           //Girilen şifrede boşluk kontrolü için döngü oluşturuldu
            for (int i = 0; i < Sifre.Length; i++)
            {
                //Girilen şifrede boşluk kontrolü için if koşulu oluşturuldu
                if (Char.IsWhiteSpace(Sifre, i))
                {
                    Console.WriteLine(" ");
                    Console.WriteLine("SİFRE BOSLUK İCEREMEZ");
                    
                    Bosluksayisi++;
                    
                }
                break;
            }




        }
        //Küçük harf sayısını metotla kontrol ediyor
        public static void KücükHarfSayisiOku()
        {

            for (int i = 0; i < SifreKarakterleri.Length; i++)
            {
                if (char.IsLower(SifreKarakterleri[i]))
                    KücükHarfSayisi++;
            }
        }
        //Büyük harf sayısı metotla kontrol ediliyor
        public static void BüyükHarfSayisiOku()
        {
            for (int i = 0; i < SifreKarakterleri.Length; i++)
            {
                if (char.IsUpper(SifreKarakterleri[i]))
                    BüyükHarfSayisi++;
            }
        }
        //Rakam sayısı metotla kontrol ediliyor
        public static void RakamSayisiOku()
        {
            for (int i = 0; i < SifreKarakterleri.Length; i++)
            {
                if (char.IsDigit(SifreKarakterleri[i]))
                    RakamSayisi++;
            }
        }
        //Sembol sayısı metotla kontrol ediliyor
        public static void SembolSayisiOku()
        {

            for (int i = 0; i < SifreKarakterleri.Length; i++)
            {
                if (!char.IsLetterOrDigit(SifreKarakterleri[i]))
                    SembolSayisi1++;


            }
            SembolSayisi = SembolSayisi1 - Bosluksayisi;
        }





    }
    internal class Program
    {

        static void Main(string[] args)
        {
           
            
            
            
                //Şifreyi kontrol eden metotlar çağırılıyor
                Kelime.SifreOku();
                Kelime.BüyükHarfSayisiOku();
                Kelime.KücükHarfSayisiOku();
                Kelime.RakamSayisiOku();
                Kelime.SembolSayisiOku();

                Console.WriteLine(" ");

                //Büyük harf sayısı yazdırılıyor
                Console.WriteLine("Büyük Harf Sayisi=" + Kelime.BüyükHarfSayisi);

                //Küçük harf sayısı yazdırılıyor
                Console.WriteLine("Kücük Harf Sayisi=" + Kelime.KücükHarfSayisi);

                //Rakam sayısı yazdırılıyor
                Console.WriteLine("Rakam Sayisi=" + Kelime.RakamSayisi);

                //Sembol sayısı yazdırılıyor
                Console.WriteLine("Sembol Sayisi=" + Kelime.SembolSayisi);

                //Şifrenin uzunluğu kontrol ediliyor
                if (Kelime.SifreKarakterleri.Length < 9)
                {
                    Console.WriteLine(" ");
                    Console.WriteLine("LÜTFEN 9 VEYA 9'DAN DAHA FAZLA KARAKTER GİRİNİZ");
                }

                //Şifrenin uzunluğuna göre puan artışı sağlanıyor
                else
                {
                    Kelime.PuanSayici += 10;
                }
                //Sembol sayısına göre puan artışı yapılıyor
                for (int i = 0; i < Kelime.SembolSayisi; i++)
                {
                    Kelime.PuanSayici += 10;
                }

                //Büyük harf sayısına göre puan artışı sağlanıyor
                for (int i = 0; i < Kelime.BüyükHarfSayisi; i++)
                {
                    Kelime.PuanSayici += 10;
                    if (Kelime.BüyükHarfSayisi == 2)
                    {
                        break;
                    }
                }

                //Küçük harf sayısına göre puan artışı sağlanıyor
                for (int i = 0; i < Kelime.KücükHarfSayisi; i++)
                {
                    Kelime.PuanSayici += 10;
                    if (Kelime.KücükHarfSayisi == 2)
                    {
                        break;
                    }
                }

                //Rakam sayısına göre puan artışı sağlanıyor
                for (int i = 0; i < Kelime.RakamSayisi; i++)
                {
                    Kelime.PuanSayici += 10;
                    if (Kelime.RakamSayisi == 2)
                    {
                        break;
                    }
                }

                //Puanın yüksekliğine göre şifrenin kuvvetine karar veriliyor
                if (Kelime.PuanSayici > 70)
                {
                    Console.WriteLine(" ");
                    Console.WriteLine("SİFRE KABUL EDİLDİ");
                    Console.WriteLine("Sifrenizin Puanı=" + Kelime.PuanSayici);

                    if (Kelime.PuanSayici >= 90)
                    {
                        Console.WriteLine(" ");
                        Console.WriteLine("!!!SİFRE GÜCLÜ!!!");

                    }
                }

                //Büyük harfin olup olmadığı kontrol ediliyor
                if (Kelime.BüyükHarfSayisi == 0)
                {
                    Console.WriteLine(" ");
                    Console.WriteLine("!! BÜYÜK HARF SAYISI 0 OLAMAZ !!");
                }

                //Rakamın olup olmadığı kontrol ediliyor
                if (Kelime.RakamSayisi == 0)
                {
                    Console.WriteLine(" ");
                    Console.WriteLine("!! RAKAM SAYİSİ 0 OLAMAZ !!");
                }

                //Küçük harfin olup olmadığı kontrol ediliyor
                if (Kelime.KücükHarfSayisi == 0)
                {
                    Console.WriteLine(" ");
                    Console.WriteLine("!!KÜCÜK HARF SAYİSİ 0 OLAMAZ!!");
                }

                //Sembol olup olmadığı kontrol ediliyor
                if (Kelime.SembolSayisi == 0)
                {
                    Console.WriteLine(" ");
                    Console.WriteLine("!!SEMBOL SAYİSİ 0 OLAMAZ!!");
                }


                if (Kelime.PuanSayici < 70)
                {
                    Console.WriteLine(" ");
                    Console.WriteLine("LÜTFEN DAHA GÜCLÜ BİR SİFRE GİRİNİZ");
                }
                Console.ReadLine();
                return;

                
            
            
          
                

        }

    }

}

