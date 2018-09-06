#include <iostream>
#include <QDomDocument>
#include <QTextStream>
#include <QFile>

#include <stdlib.h>
#include <time.h>

using namespace std;

void writeXml()
{
    QDomDocument doc;
    QDomProcessingInstruction xmlInstruction = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"");
    //QDomComment comment = doc.createComment(QString::fromLocal8Bit("离开是为了更好的归来"));
    //QDomProcessingInstruction styleInstruction = doc.createProcessingInstruction("xml-stylesheet", "type=\"text/css\" href=\"style.css\"");
    doc.appendChild(xmlInstruction);  // 开始文档（XML 声明）
    //doc.appendChild(comment);  // 注释
    //doc.appendChild(styleInstruction);  // 处理指令
    // 根元素 <Blogs>
    QDomElement root = doc.createElement("targets");
    //root.setAttribute("Version", "1.0");  // 属性
    doc.appendChild(root);

    srand((unsigned)time(NULL));

    // 元素 <Blog>
    for(int i = 0; i < 1000; i++)
    {
        int x = (rand() % (1920))+ 0;
        int y = (rand() % (1080))+ 0;
        QString width1 = "12";
        QString height1 = "12";
        int index1 = i+1;

        QDomElement child = doc.createElement("target");
        root.appendChild(child);

        // 元素 <作者>、<时间>、<个人说明>
        QDomElement author = doc.createElement(QString::fromLocal8Bit("X"));
        QDomElement home = doc.createElement(QString::fromLocal8Bit("Y"));
        QDomElement instruction = doc.createElement(QString::fromLocal8Bit("Width"));
        QDomElement height = doc.createElement(QString::fromLocal8Bit("Height"));
        QDomElement shap = doc.createElement(QString::fromLocal8Bit("Shape"));
        QDomElement index = doc.createElement(QString::fromLocal8Bit("Index"));

        child.appendChild(author);
        child.appendChild(home);
        child.appendChild(instruction);
        child.appendChild(height);
        child.appendChild(shap);
        child.appendChild(index);

        // 元素的文本数据
        QDomText authorText = doc.createTextNode(QString::number(x, 10));
        QDomText homeText = doc.createTextNode(QString::number(y, 10));
        QDomText instructionText = doc.createTextNode(width1);
        QDomText heightTxt = doc.createTextNode(height1);
        QDomText shapTxt = doc.createTextNode("rectangle");
        QDomText indexTxt = doc.createTextNode(QString::number(index1, 10));

        author.appendChild(authorText);
        home.appendChild(homeText);
        instruction.appendChild(instructionText);
        height.appendChild(heightTxt);
        shap.appendChild(shapTxt);
        index.appendChild(indexTxt);
    }


    // 保存 XML 文件
    QString strFile("shapeTargets.xml");
    QFile file(strFile);
    // 只写模式打开文件
    if (file.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&file);
        doc.save(out, QDomNode::EncodingFromDocument);
        file.close();
    }
}

int main()
{
    writeXml();
    cout << "Hello World!" << endl;
    return 0;
}
