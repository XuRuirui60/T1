namespace T1
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            groupBox1 = new GroupBox();
            comboBox1 = new ComboBox();
            button1 = new Button();
            button2 = new Button();
            label1 = new Label();
            label2 = new Label();
            groupBox1.SuspendLayout();
            SuspendLayout();
            // 
            // groupBox1
            // 
            groupBox1.BackColor = Color.LightGreen;
            groupBox1.Controls.Add(label2);
            groupBox1.Controls.Add(label1);
            groupBox1.Controls.Add(button2);
            groupBox1.Controls.Add(button1);
            groupBox1.Controls.Add(comboBox1);
            groupBox1.Location = new Point(80, 96);
            groupBox1.Margin = new Padding(6, 6, 6, 6);
            groupBox1.Name = "groupBox1";
            groupBox1.Padding = new Padding(6, 6, 6, 6);
            groupBox1.Size = new Size(539, 210);
            groupBox1.TabIndex = 0;
            groupBox1.TabStop = false;
            groupBox1.Text = "Device Connect";
            // 
            // comboBox1
            // 
            comboBox1.FormattingEnabled = true;
            comboBox1.Location = new Point(30, 57);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(181, 46);
            comboBox1.TabIndex = 0;
            // 
            // button1
            // 
            button1.Location = new Point(246, 57);
            button1.Name = "button1";
            button1.Size = new Size(123, 51);
            button1.TabIndex = 1;
            button1.Text = "Open";
            button1.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            button2.Location = new Point(386, 57);
            button2.Name = "button2";
            button2.Size = new Size(123, 51);
            button2.TabIndex = 2;
            button2.Text = "Close";
            button2.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(30, 141);
            label1.Name = "label1";
            label1.Size = new Size(214, 38);
            label1.TabIndex = 3;
            label1.Text = "Device Status:";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.BackColor = Color.Red;
            label2.Location = new Point(246, 141);
            label2.Name = "label2";
            label2.Size = new Size(215, 38);
            label2.TabIndex = 4;
            label2.Text = "Device Offline";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(18F, 38F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1447, 918);
            Controls.Add(groupBox1);
            Font = new Font("Microsoft JhengHei UI", 18F, FontStyle.Regular, GraphicsUnit.Point, 136);
            Margin = new Padding(6, 6, 6, 6);
            Name = "Form1";
            Text = "109 學年度 工業類科學生技藝競賽 電腦修護職種 第二站 崗位號碼: 01";
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private GroupBox groupBox1;
        private Button button1;
        private ComboBox comboBox1;
        private Label label2;
        private Label label1;
        private Button button2;
    }
}
